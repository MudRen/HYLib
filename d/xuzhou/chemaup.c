inherit ROOM;

void create()
{
	set("short", "������¥");
	set("long", @LONG
����һ��ܴ�Ŀͷ�������ʮ�ּ�ª����ǽ����ʮ����Сľ������
�ٿ��������¶��ԣ������Ӷ��Ǻ����Ĵ������������Ŵ��ǿյģ���
������ŵ����˹�ȥ��
LONG );
	set("sleep_room", "1");
	set("no_fight", "1");
	set("no_clean_up", 0);
	set("exits", ([
		"down" : __DIR__"chema",
	]));
	setup();
}

int valid_leave(object ob,string dir)
{
   ob->delete_temp("gived_money");
   
   return ::valid_leave(ob,dir);
   
}