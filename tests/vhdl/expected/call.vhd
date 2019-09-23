ARCHITECTURE arch OF module IS
BEGIN
    data <= (i_data(i_data'range) AND i_mask);
END ARCHITECTURE;
