int main() {
    TOF *tof;
    char path[100];
    char mode;

    printf("Enter file path: ");
    scanf("%s", path);

    printf("Open mode (A: Existing, N: New): ");
    scanf(" %c", &mode);

    tof = open_file(path, mode);
    if (tof == NULL) {
        printf("Error opening file.\n");
        return -1;
    }

    SparseIndex sparseIndex[SIZE];
    DenseIndex denseIndex[SIZE];
    int sparseCount = buildSparseIndex(sparseIndex, tof);
    int denseCount = buildDenseIndex(denseIndex, tof);

    saveSparseIndex(sparseIndex, sparseCount, "sparse_index.dat");
    saveDenseIndex(denseIndex, denseCount, "dense_index.dat");

    printf("Indexes built and saved successfully.\n");

    close(tof);
    return 0;
}
