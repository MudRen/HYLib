// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�ɷ���");
	set("long", @LONG
�����Ǹ����ķɷ��š�����͵��˳��У�Զ����ɽ�˺�����������
��������������һ����·ͨ����ԭ����������һЩִ�ڵı�ʿ��������
��Ķ���������ʿ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"east" : __DIR__"qinglong-2",
        	"west" : __DIR__"edao1",
        	"southwest":__DIR__"dadi",
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
    ob->add_temp_array("xunluo_dir","qinglong");
  return ::valid_leave(ob,dir);
}
