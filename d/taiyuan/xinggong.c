// /d/taiyuan/damen.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "�й�");
	set("long", @LONG
�������̫ԭ���й�����˵�����й�����������������ɵģ�����
Ԩ���ʱ����������Ϊ��ʱ�Ĵ�Ӫ��
LONG
	);
set("exits", ([
                "west" : __DIR__"beidajie2", 
	]));
 set("objects",([ __DIR__"npc/mingong":2,]));
       setup();
	replace_program(ROOM);
}
