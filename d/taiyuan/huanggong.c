// /d/taiyuan/huanggong.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�ʹ�");
	set("long", @LONG
����ԭ������쾵���̫ԭ���й�����Ϊ�����ʱ��̣����Խ����
��������������Ԩ�������ռ����������ʹ�Ҳ��ֻ�п��صľ����ˡ�
LONG
	);
set("outdoors", "taiyuan");
set("exits", ([
                "south" : __DIR__"dongdajie1", 
	]));
            set("objects", ([
                __DIR__"npc/shiwei": 2,
        ]));
       setup();
	replace_program(ROOM);
}	
