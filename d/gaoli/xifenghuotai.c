// Room in ����
inherit ROOM;
void create()	
{
	set("short", "���̨");
	set("long", @LONG	
���Ǹ���λ������ɽ���ϵ�һ�����̨���м����ٱ���������۲�
�������������Կ������߸����ǵ�ȫò���ǳ�׳�ۡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"eastdown" : __DIR__"shanlu5",
		
	]));
     set("objects",([
       __DIR__"npc/bing":2,
       ]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","xfenghuotai");
  return ::valid_leave(ob,dir);
}
