// Room in ����
inherit ROOM;
void create()	
{
	set("short", "���̨");
	set("long", @LONG	
���Ǹ���λ�ں��ߵ�һ�����̨���м����ٱ���������ۺ��ϵ���
����������ȥ��һƬ�̲���û�б߼ʡ��������ڻ��Ƿ�ƽ�˾���
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"eastdown" : __DIR__"xiaolu2",
	]));
	set("objects",([
	  __DIR__"npc/bing":2,
	  ]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","fenghuotai");
  return ::valid_leave(ob,dir);
}
