import fitz
import pandas as pd
import os

# Set base path to the folder containing this script
base_path = os.path.dirname(__file__)

# Full paths to input files
client_path = os.path.join(base_path, "clients.xlsx")
pdf_path = os.path.join(base_path, "flight_schedule.pdf")

# Load Excel
clients = pd.read_excel(client_path)
clients.to_csv(os.path.join(base_path, "clients_data.csv"), index=False)

# Load PDF
with fitz.open(pdf_path) as doc:
    text = "\n".join([page.get_text() for page in doc])

with open(os.path.join(base_path, "flight_text.txt"), "w", encoding="utf-8") as f:
    f.write(text)

print("✅ Data exported successfully.")
