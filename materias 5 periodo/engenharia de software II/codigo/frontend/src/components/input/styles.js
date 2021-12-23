import styled from 'styled-components';

export const Section = styled.div`
  display: flex;
  flex-direction: column;
  width: ${({ size }) => size};
  padding: 5px;

  label {
    color: ${({ theme }) => theme.colors.light};
  }

  input {
    width: 100%;
    height: 35px;
    padding-left: 5px;
    border: 1px solid transparent;
    border-radius: 6px;
    font-size: 1.0rem;
    color: ${({ theme }) => theme.colors.dark};

    :read-only{
      cursor: no-drop;
    }
  }

  input:focus {
    outline: 2px solid #6B33FF;
  }
`;
