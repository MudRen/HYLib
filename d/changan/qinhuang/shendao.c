// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "���");
    set("long", @LONG
������࣬�Զ���������������ʨ��ⳡ����ա������������
��ʯ����ޣ�����������������ʮ���Զ�ʮ����������������������
����ʹ���������˴�˵���ɽ硣�ڵ����������£���ʯ�޻�׻�����
��η��˪��ѩ��
LONG
);
    set("exits", ([
       "north" :__DIR__"shidao",
       "west" :__DIR__"mumen",
]));
    setup();
    replace_program(ROOM);
}
