import styled from 'styled-components';

export const DynamicButton = styled.button`
  width: ${({ size }) => size};
  height: 40px;
  cursor: pointer;
  margin: 10px;
  background-color: ${({ theme }) => theme.colors.secondary};
  color: ${({ theme }) => theme.colors.light};
  border: none;
  border-radius: 10px;
  box-shadow: 0 2px #10002B;
  font-size: 1.0rem;
  font-weight: normal;

  :hover {
    background-color: ${({ theme }) => theme.colors.third};
    color: ${({ theme }) => theme.colors.light};
  }

  :active {
    background-color: ${({ theme }) => theme.colors.light};
    color: ${({ theme }) => theme.colors.secondary};
    box-shadow: 0 1px #10002B;
    transform: translateY(1px);
  }
`;