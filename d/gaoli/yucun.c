// Room in ����
inherit ROOM;
void create()	
{
	set("short", "���");
	set("long", @LONG
���Ǹ�����һ����壬������˶�������Ϊ����������ͣ�����洬��
����������Ŵ󵣴󵣵������ţ�������㻹���ʱĻ�����
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"northeast" : __DIR__"jiangkou",
		"east" : __DIR__"haigang",
                "southeast" : __DIR__"yuchuan",
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","yucun");
  return ::valid_leave(ob,dir);
}
