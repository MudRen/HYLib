// /d/taiyuan/shanghang.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG
���������һ����������������ר�Ÿ�����ԭ������֮��������
�ͣ�����Ҳ�������̶���̫ԭ�����֮����
LONG
	);
set("exits", ([
                "south" : __DIR__"xidajie1", 
	]));
	set("objects",([
	__DIR__"npc/li":1,
	]));
       setup();
	replace_program(ROOM);
}	
