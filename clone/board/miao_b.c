inherit BULLETIN_BOARD;

void create()
{
        set_name("��ҵ������԰�", ({ "board" }) );
        set("location", "/d/zhongzhou/miaojia_houting");
        set("board_id", "miao_b");
        set("long", "����һ������ҵ��ӽ��������԰塣\n" );
        setup();
        set("capacity", 100);
        replace_program(BULLETIN_BOARD);
}

