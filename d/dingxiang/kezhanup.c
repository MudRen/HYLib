// /d/yazhang/kefangup.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��ջ��¥");
	set("long", @LONG
��˳��¥�ݵ��Ͽ�ջ�Ķ�¥�������Ž����ţ���ϸ��������������
˯���ĺ�������
LONG
	);
set("exits", ([
                 "south" : __DIR__"shuifang",  
                  "down" : __DIR__"kezhan",  
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(dir=="down")
  ob->delete_temp("gived_money");
  return ::valid_leave(ob,dir);
}
