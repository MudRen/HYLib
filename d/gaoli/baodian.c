// Room in ����
inherit ROOM;
void create()	
{
	set("short", "���۱���");
	set("long", @LONG	
�������龲�µĴ��۱���м���ɮ�����������о����������
�����ƣ�һ��ׯ�ϵ����ա��м��������������ݷ��棬���������дʣ�
��֪������ƽ�������������ˡ�
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
		"out" : __DIR__"miaodoor",
	      	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","simiao");
  return ::valid_leave(ob,dir);
}
