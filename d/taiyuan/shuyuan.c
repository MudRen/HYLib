// /d/taiyuan/shuyuan.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��Ժ");
	set("long", @LONG
����һλ�������꿪����Ժ����ǰ������Ϸ����������徭���Ӿ�
�伯֮����鼯�����Ե�������һ������������Ϲ���һ��������ͼ��
����λ��������֮����
LONG
	);
set("exits", ([
                "east" : __DIR__"nandajie1", 
	]));
	set("objects",([
	__DIR__"npc/zhao":1,
	]));
       setup();
	replace_program(ROOM);
}	
