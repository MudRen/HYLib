// /d/yazhang/kezhan.c
// Room in ����
// laowuwu 99/05/05
inherit ROOM;
void create()	
{
	set("short", "��ջ");
	set("long", @LONG
������ڷ������������ӣ����������������÷������Ժ����һ��
��̨���ƹ�����ڹ�̨�������۾����Ƕ�Ʒ�裬һ��С���æ��æȥ
�к����ˡ�
LONG
	);
set("exits", ([
                 "west" : __DIR__"beidajie1",  
                  "up" : __DIR__"kezhanup",  
	]));
	set("objects",([
	__DIR__"npc/xiaoer4":1,
	]));
       setup();
	
}	
int valid_leave(object ob,string dir)
{
  if(!ob->query_temp("gived_money")&&dir=="up")
  return notify_fail("��������Ǯ���ס������\n");
  return ::valid_leave(ob,dir);
}
