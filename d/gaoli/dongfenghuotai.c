// Room in ����
inherit ROOM;
void create()	
{
	set("short", "���̨");
	set("long", @LONG
�����Ǹ����Ķ����̨�������������߾���������Լ�ʱ����ս
���������ϱ��ߣ����Ǹ����ĳ������ˡ�����䱸ɭ�ϣ��м����ٱ���
���������������ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southdown" : __DIR__"shulin3",
		//"north":__DIR__"beifenghuotai",
	]));
      set("objects",([
         __DIR__"npc/bing":2,
         ]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","dongfenghuotai");
  return ::valid_leave(ob,dir);
}