//cool 98.4.18

inherit ROOM;

void create()
{
	set("short", "��Ժ");
	set("long", @LONG
�����Ǻ�Ժ���ˣ����ܶ��ǲ˵أ������Ǹ�Сɽ�£������涼��
�����Χ��Ĳ˵أ����Ÿ����Ĳˣ���ʺ����ã�ҡҡ��׹��������
��ûʲô�˴���
LONG);
	set("exits", ([
              "west" : __DIR__"caidi2",
              "east" : __DIR__"caidi1",
	      "south" : __DIR__"houyuan2",
        ]));
        set("outdoors", "���");
	setup();
        replace_program(ROOM);
}

