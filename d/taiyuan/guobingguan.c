// /d/taiyuan/guobingguan.c
// Room in ̫ԭ
// rich 99/05/05
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
������Ԩ����󣬽����Ĺ����ݣ��д�����ʹ�ߣ�������ԨǨ����
��������Ҳ�Ͷ���ͨ���տ��ţ�����һ�Ҵ��ջ��
LONG
	);
set("exits", ([
                "north" : __DIR__"dongdajie1", 
                "south" : __DIR__"shuifang",    
	]));
	set("objects",([
	__DIR__"npc/xiaoer3":1,
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
   if(!ob->query_temp("gived_money")&&dir=="south")
   return notify_fail("��ô�����ס����\n");
   return ::valid_leave(ob,dir);
}
