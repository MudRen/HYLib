//Room: majiu1.c ���
//Date: Oct. 2 1997 by That

inherit ROOM;

void create()
{
      set("short","���");
      set("long",@LONG
���ǿ͵�����ǣ����깩Ӧ���ʲ��ϡ�������紾�ӣ�����ǻ��
��ǣ����Ǻ����տ���������ι�����㣬��ϴˢ�ø�Ǭ������һֱ�ź�
������·����������µ���ľ���϶���һ����ľ��(paizi)��
    ����жѷ������Ѳ��ϣ�������һ����ۡ�
LONG);
      set("outdoors", "city");
      set("no_fight", "1");
      set("no_beg", "1");
      set("no_clean_up", 0);
      set("objects", ([
               __DIR__"npc/zaohongma": 1,
               __DIR__"npc/huangbiaoma": 1,
               __DIR__"npc/ziliuma": 1,
               __DIR__"npc/mafu": 1,
      ]));
      set("item_desc", ([
          "paizi": @TEXT
������ֻҪ�����һ�����������Ϳ��Թ͵�һƥ���ˡ�

ǰ��      ������:  ridebj
          ���ݳ�:  ridesz
          ���ݳ�:  ridehz
          ���ݳ�:  ridefz
          �����:  ridedl
          ������:  ridexy
          ���ǳ�:  rideyd
          ������:  rideyl
          ��ɽ��:  ridefs
          ����ɽ:  rideem
          ���ݳ�:  rideyz
          ��ƽ��:  rideyp
          �����:  ridejl
          ������:  rideca
          �ɶ���:  ridecd                                               
          ������:  ridewx                                               
          ���ݳ�:  ridelz                                               
          ���ݳ�:  rideyz                                                      
          ��ͼ������:  rideht
          ���ݳ�:  ridejingzhou
          ������:  ridekm
TEXT]));
      set("exits",([ /* sizeof() == 1 */
          "west"      : __DIR__"kedian",
      ]));
      setup();
     
}
void init()
{
	add_action("do_yao","yaoche");
}
int do_yao()
{
	object *inv,kicker;
	int sizeinv,n,tt;
object me;
me = this_player();
if(!me->query("marks/mengzhu"))
		return notify_fail("��û�г�����Ȩ�ޡ�\n");
   if (me->query_temp("che"))
		return notify_fail("���Ѿ�Ҫ�����ˡ�\n");
		inv=all_inventory(me);
		sizeinv=sizeof(inv);
	
		while (sizeinv--)
		{
       			if (inv[sizeinv]->is_character())  
     				return notify_fail("�����ȥ�����˿ڣ�\n");
       		
		}
	me->set_temp("che",1);
message_vision("$N������һ�����Ҵ�ææ����ȥ�ˡ�\n",me);
if (me->query("shen")<0)  me->move("/d/biwu/a11");
else me->move("/d/biwu/b11");
message_vision("$NͻȻ������������ǰ��\n",me);
return 1;
}
