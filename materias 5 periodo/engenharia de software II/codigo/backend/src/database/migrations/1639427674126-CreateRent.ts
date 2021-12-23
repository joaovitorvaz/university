import { MigrationInterface, QueryRunner, Table } from "typeorm";

export class CreateRent1639427674126 implements MigrationInterface {
  public async up(queryRunner: QueryRunner): Promise<void> {
    await queryRunner.createTable(
      new Table({
        name: "rents",
        columns: [
          {
            name: "id",
            type: "varchar",
            isPrimary: true,
          },
          {
            name: "user_id",
            type: "varchar",
          },
          {
            name: "game_id",
            type: "varchar",
          },
          {
            name: "created_at",
            type: "timestamp",
            default: "now()",
          },
          {
            name: "expired_at",
            type: "timestamp",
          },
        ],
        foreignKeys: [
          {
            name: "FKRentsUsers",
            referencedTableName: "users",
            referencedColumnNames: ["id"],
            columnNames: ["user_id"],
            onUpdate: "CASCADE",
            onDelete: "NO ACTION",
          },
          {
            name: "FKRentsGames",
            referencedTableName: "games",
            referencedColumnNames: ["id"],
            columnNames: ["game_id"],
            onUpdate: "CASCADE",
            onDelete: "NO ACTION",
          },
        ],
      })
    );
  }

  public async down(queryRunner: QueryRunner): Promise<void> {
    await queryRunner.dropTable("rents");
  }
}
