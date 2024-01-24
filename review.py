import os
import random

def find_problem_by_criteria(root_dir, search_type, search_value):
    """
    Finds a random problem based on given search criteria (tag or difficulty) in the 'problem' directory.
    """
    matching_problems = []

    for subdir, dirs, files in os.walk(root_dir):
        if 'tag' in files:
            tag_file_path = os.path.join(subdir, 'tag')

            with open(tag_file_path, 'r') as file:
                lines = file.readlines()
                if search_type == 'difficulty' and lines[0].strip().lower() == search_value.lower():
                    matching_problems.append(os.path.basename(subdir))
                elif search_type == 'tag' and len(lines) > 1:
                    if search_value.lower() in [tag.strip().lower() for tag in lines[1:]]:
                        matching_problems.append(os.path.basename(subdir))

    # Randomly select one problem.
    # print(f"There are {len(matching_problems)} problems in total.")
    return random.choice(matching_problems) if matching_problems else None

def main():
    root_directory_path = 'Problems'

    while True:
        search_type = input("Search by 'tag' or 'difficulty'? (type 'exit' to quit) ")
        if search_type.lower() not in ["exit", "tag", "difficulty"]:
            print(f"what the hell was {search_type}?")
            print("\n")
            continue

        if search_type.lower() == 'exit':
            break

        search_value = input(f"Enter the {search_type}: ")

        selected_problem = find_problem_by_criteria(root_directory_path, search_type, search_value)

        if selected_problem:
            print(f"Try this one: {selected_problem}")
        else:
            print(f"No problems found for {search_type} '{search_value}'.")

        print("\n")

if __name__ == "__main__":
    main()
