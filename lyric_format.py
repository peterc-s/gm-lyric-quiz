import sys

def convert_lyrics_format(input_text):
    """
    Convert lyrics from stdin to the specified format with CLAY_STRING syntax.
    Title is extracted from the first line (must be in quotes).
    Escapes any quotes in both title and lyrics.
    
    Args:
        input_text (str): The complete input text including title and lyrics
    
    Returns:
        str: Formatted string in the target format
    """
    # Split input into lines
    lines = input_text.strip().split('\n')
    
    # Extract title from first line (assuming it's in quotes)
    title = lines[0].strip('"').replace('"', '\\"')
    
    # Get lyrics (everything after the first line)
    lyrics = '\n'.join(lines[2:])  # Skip the title and the blank line after it
    
    # Process lyrics: ensure consistent line endings
    processed_lyrics = lyrics.strip().replace('\r\n', '\n')
    
    # Build the formatted lyrics string with proper indentation and quote escaping
    lyrics_lines = processed_lyrics.split('\n')
    formatted_lines = []
    for line in lyrics_lines:
        if line:
            # Escape any quotes in the line
            escaped_line = line.replace('"', '\\"')
            formatted_lines.append(f'                "{escaped_line}\\n"')
        else:
            formatted_lines.append('                "\\n"')
    
    # Join all lines
    formatted_lyrics = '\n'.join(formatted_lines)
    
    # Construct the final output
    output = f'''    (Song) {{
        .title = CLAY_STRING("{title}"),
        .lyrics = CLAY_STRING(
{formatted_lyrics}
                ),
    }},'''
    
    return output

if __name__ == "__main__":
    # Read all input from stdin
    input_text = sys.stdin.read()
    
    # Convert and print the result
    result = convert_lyrics_format(input_text)
    print(result)
