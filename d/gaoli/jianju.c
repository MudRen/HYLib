// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "���Ǽ���");
	set("long", @LONG
������Ǹ����ı��Ǽ����ˡ���ǰ��һ����ǽ���������ָ���Ҳ��
��Ծ�����ſ�վ�ż����ٱ������������µش������㡣���治ʱ������
�˲ҽе�������
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"shanlu16",
               	//"west":__DIR__"jianju",
	]));
	set("objects",([
         __DIR__"npc/bing":4,
         ]));
       setup();
	
}
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","jianyu");
  return ::valid_leave(ob,dir);
}
