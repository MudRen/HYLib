// "suiye"/zahuopuu
// Room in ��Ҷ
// laowuwu 99/03/28
inherit ROOM;
void create()	
{
	set("short","�ӻ���");
	set("long", @LONG
������Ҷ�ʤ����"�ٻ�ȫ"�ӻ��̡���˵������С���Ͼ�ƫ����
���Ʒ����û������˵����Щ�ڵ�û�еĶ�������ؼ���ϡ��Źֵ���
���챦���������������Ŀ��ˡ���������ϰ��������ײ���β��Ҫ����
���ף��������ס�
LONG);
set("exits", ([
		
                "east"  : __DIR__"beidajie2",
               
	]));
	set("objects",([
	  __DIR__"npc/xiaoer2":1,
	  ]));
       setup();
	replace_program(ROOM);
}	
