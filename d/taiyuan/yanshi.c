// /d/taiyuan/yanshi.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��˾");
	set("long", @LONG
̫ԭλ����½�������Σ����Զ�Ҫ���غ�����������Σ���˾��
��ָ�������������Σ�������ȡ˰��
LONG
	);
set("exits", ([
                "north" : __DIR__"xidajie2", 
	]));
       setup();
	replace_program(ROOM);
}	
