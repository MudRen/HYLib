// Room: /d/city/pinganmen
 inherit ROOM;
 
 void create ()
{
   set ("short", "ƽ����");
   set ("long", @LONG
������칬ƽ���ǵ���ڣ��������޵�ׯ�ϡ��Ӵ˴����У�
�͵�ƽ���� �ˡ�һ��ƽ���ǣ���Զ����ƽ��������Ѫ�ȷ��꣬
��һ�������ľ���ȥ���� ��������У���ͽ��뽭���ˡ�
LONG); 
        set("no_fight",1);
         set("no_steal",1);
         set("pingan",1);
         set("no_beg",1); 	
   set("outdoors", "pingan"); 
  set("exits", ([ /* sizeof() == 2 */  
 "east" : __DIR__"west3",   
 "up" : __DIR__"gate/wupgate",   
  "down" : "/d/city/guangchang", ]));
	set("objects", ([
		__DIR__"npc/bing" : 2,
	]));
    setup();
} 
 int valid_leave(object me, string dir) 
{
       if (  me->query_temp("xunchen")< 1 && dir == "up" )
        return notify_fail("ʿ��˵������һ��,���������˵һ��,����Ѳ�ǣ�\n");
 	if ( me->query("PKS") >= 3 && dir == "east" )
 	return notify_fail("��ɱ��̫�����ң�ƽ���ǲ���ӭ�㣡\n");
 	 	if ( me->query("age") >= 25 && dir == "east")
 	return notify_fail("����ô������Ҳ�����ƽ���ǣ�\n"); 
 	return ::valid_leave(me, dir);
}
