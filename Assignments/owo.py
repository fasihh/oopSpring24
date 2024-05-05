import os

std_id = "23K0018"
files = [file for file in os.listdir() if file != os.path.basename(__file__)]

def handle_file(file):
	new_lines = []
	with open(file) as cpp_file:
		lines = cpp_file.readlines()
		new_lines = [f"{line}\tcout << \"{std_id}\" << endl;\n" if line == "int main() {\n" else line for line in lines]
	with open(file, "w") as cpp_file:
		cpp_file.write("".join(new_lines))


for i, file in enumerate(files):
	#handle_file(file)
	os.rename(file, f"A2-Q{i+1}[{std_id}].cpp")

