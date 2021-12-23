import { MigrationInterface, QueryRunner, Table } from "typeorm";

export class CreateGames1639263104518 implements MigrationInterface {
  public async up(queryRunner: QueryRunner): Promise<void> {
    await queryRunner.createTable(
      new Table({
        name: "games",
        columns: [
          { name: "id", type: "varchar", isPrimary: true },
          {
            name: "name",
            type: "varchar",
          },
          {
            name: "genre",
            type: "varchar",
          },
          {
            name: "ageRestriction",
            type: "int",
          },
          {
            name: "price",
            type: "double",
          },
          {
            name: "platform",
            type: "varchar",
          },
          {
            name: "description",
            type: "varchar",
          },
          {
            name: "logo",
            type: "varchar",
          },
          {
            name: "created_at",
            type: "timestamp",
            default: "now()",
          },
          {
            name: "updated_at",
            type: "timestamp",
            default: "now()",
          },
        ],
      })
    );
  }

  public async down(queryRunner: QueryRunner): Promise<void> {
    await queryRunner.dropTable("games");
  }
}
