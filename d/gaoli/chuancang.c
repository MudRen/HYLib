// Room in ����
inherit ROOM;
void create()	
{
	set("short", "����");
	set("long", @LONG	
������ս���Ĵ��ա���������û��ʲô�ˡ������Ϸ���һ���裬��
��Щ���ȣ�����������˸ճ�ȥ���á��Ա߻���һ��ͼֽ���ƺ��ǹ���
��ս�����ͼֽ��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"out" : __DIR__"jiaban",
		//"enter":__DIR__"chuancang",
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","zhanchuan");
  return ::valid_leave(ob,dir);
}
