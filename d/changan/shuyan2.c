inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������̫�׾�ʿ���鷿�����ܳ����Եùŵ�����£������һ��
��ɫ�����̴ľ��ܣ�������ͯ������ī������
LONG
        );
        set("no_clean_up", 0);
        set("no_fight", "1");
        set("sleep_room", "1");
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"shuyuan",
]));
        setup();
        replace_program(ROOM);
}

