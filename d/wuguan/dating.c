//cool 98.4.18
inherit ROOM;

void create()
{
	set("short", "��ݴ���");
	set("long", @LONG
��������ݴ��������п�������һ�Ű����������Ϲ��Źع�����λ��
�Ա߷���������ɻ�ƿ�����ż�֧��ȸ�ᣬǽ��д�Ŵ���һ�����䡱��
���������Щ���ڽ����ϴ������ֽ�ϴ�����ˣ������������������ݣ�
�������Ǹ����ȣ�һֱͨ����������ҡ�
LONG);
	set("exits", ([
	       "southdown" : __DIR__"dayuan2",
               "enter" : __DIR__"lang5",
	       "westdown" : __DIR__"shilu-2",
	       "eastdown" : __DIR__"shilu-1",
        ]));
        set("objects", ([
           __DIR__"npc/zhu" : 1,
        ]));
	setup();
        replace_program(ROOM);
}


