// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��ʤ��");
	set("long", @LONG
�����Ǹ����ĵ�ʤ�š�����͵��˳��У�Զ����ɽ�˺�����������
��������������һ����·ͨ��ۿڡ���������һЩִ�ڵı�ʿ��������
��Ķ���������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"south" : __DIR__"dadao6",
        	"north" : __DIR__"zhuque-2",
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
    ob->add_temp_array("xunluo_dir","zhuque");
  return ::valid_leave(ob,dir);
}
