// /d/gaoli/jiaojunchang
// Room in ����
// rich 99/03/28
inherit ROOM;
void create()	
{
	set("short", "�Ͼ���");
	set("long", @LONG
����һ���Ͼ������տ�����һ����Ҳû�У�ֻ�з紵����Ҷ������
����������ۼ����ӣ�����Ĺٱ�����Ҳ������У�Զ���Ĵ�̨�ǻ���
������̨��
LONG
	);
set("outdoors", "/d/gaoli");
set("exits", ([
                "northeast":__DIR__"dadao8",  
                 "southwest":__DIR__"dadao7",   
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(ob->query_temp("gaoli_xunluo"))
    ob->add_temp_array("xunluo_dir","jjc");
  return ::valid_leave(ob,dir);
}
