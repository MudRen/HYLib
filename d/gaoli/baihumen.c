// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "������");
	set("long", @LONG
�����Ǹ����ĳ����š�����͵��˳��У�Զ����ɽ�˺�����������
��������������һ����·ͨ�����޺Ͱټá���������һЩִ�ڵı�ʿ��
��������Ķ���������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"west" : __DIR__"baihu-2",
        	"east" : __DIR__"dadao1",
        	"northeast":__DIR__"shulin1",
	]));
set("objects",([
  __DIR__"npc/guanbing":2,
  __DIR__"npc/wujiang":1,
  ]));
       setup();
	
}
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","baihu");
  return ::valid_leave(ob,dir);
}
