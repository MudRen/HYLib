inherit ROOM;
int check_container(object ob);
void create()
{
        set("short", "ǧ��¥��");
        set("long", @LONG
��¥�ھ���������ԭ����������¥�����������ľƣ�Ҳ����õľƣ�
����������Ů�ˣ�Ҳ������ζ����Ů�ˣ����������ķ���Ҳ����õķ���
���������ƣ�����һ�飬�ָ���һ�����ͽ��ң�
[1;35m
			��ɫ�ޱ�
[2;37;0m
LONG
        );
        set("exits", ([ /* sizeof() == 4 */
  "south" : "/d/beijing/dongcha1",
  "west" : __DIR__"pingfeng",
]));
        set("item_desc", ([
                "sign": @TEXT
ǧ��¥¥�棺
�������ɼд��κα�����¥��
�����Է�����ǧ��¥С������Ϊû������������
�������ɼд��κ�ʳ���ˮ��¥��
������ҳ������������ѣ��໥�������ӣ�
������ܣ�������¥�洦�á�
��������ͷ������Խ�࣬���ܵ��ź�Խ�á�
TEXT
        ]) );

	set("outdoors","fengyun");
	set("no_fight",1);
	set("no_magic",1);
	set("NONPC",1);
        set("objects", ([
        __DIR__"npc/guinu" : 2,
        "/d/city2/npc/laobaopo" : 1,
                        ]) );
        set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",0);
	setup();
}
int valid_leave(object me, string dir)
{
        object ob;
	object *inv;
	int i;
//        if( dir == "west" && !(int)this_object()->query("enter_permission") && ob = present("guinu",this_object()))
//        {
//		message_vision("$N�����죬��$nЦ��˵��ʱ�����磬�����ǻ���˯����������\n", ob, me);
//		return		notify_fail("����һ�°ɣ�\n");
//        }
        if( dir == "west" &&  ob = present("guinu",this_object()))
        {
//                inv = all_inventory(me);
//                for(i=0; i<sizeof(inv); i++)
//                {
//                        if((int)inv[i]->query("weapon_prop"))
//			return notify_fail(ob->name()+"����Ц����ǧ��¥��ǧ��¥��¥�棬���뿴�ƣ�\n");
//			if((int)inv[i]->query("food_remaining") != 0)
//			return notify_fail(ob->name()+"����Ц����ǧ��¥��ǧ��¥��¥�棬���뿴�ƣ�\n");
//			if((int)inv[i]->query("liquid/remaining") !=0)
//			return notify_fail(ob->name()+"����Ц����ǧ��¥��ǧ��¥��¥�棬���뿴�ƣ�\n");
//			if((int)inv[i]->is_container()) 
//			if(check_container(inv[i]))
//			return notify_fail(ob->name()+"����Ц����ǧ��¥��ǧ��¥��¥�棬���뿴�ƣ�\n");
//		}
        me->set("food",0);
        me->set("water",0);
        }
	return 1;
}

int check_container(object ob)
{
object *inv;
int i;
inv = all_inventory(ob);
 for(i=0; i<sizeof(inv); i++)
 {
                        if(inv[i]->query("weapon_prop"))
                        return 1;
                        if(inv[i]->query("food_remaining") != 0)
                        return 1;
                        if(inv[i]->query("liquid/remaining") !=0)
                        return 1;
                        if(inv[i]->is_container()) 
                        if(check_container(inv[i]))
                        return 1;
 }
return 0;
}
