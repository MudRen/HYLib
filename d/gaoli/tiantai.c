// /d/gaoli/xuanwumen
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "��̨");
	set("long", @LONG
�����������̨���������������ĵط���������һ����㳡����
���ޱȡ���������Կ����ϱ߸����ǵķ�⡣�����м��������������
��Ķ�������������Щ���ء�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"southdown" : __DIR__"guangchang",
        	//"northup":__DIR__"tiantai",
	]));
       setup();
	
}

int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","tiantai");
  return ::valid_leave(ob,dir);
}
