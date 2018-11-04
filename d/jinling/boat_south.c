inherit ROOM;


void create()
{
    set("short", "�����ϰ�");
    set("long", @LONG
��ǰ��һ�����η����Ĵ�(river)���������������۾�����
�����ɴ���������������һ�����������̯����Ҿͽ������ڰ�
�ߣ���������֧һ��ľ�壬���ϰ����˻�������ĺ������㡣��
ȥ��Զ�����������Ϻӿڣ����ٹ����Ͷ�������ȴ��ɴ��ڶɡ�
LONG
    );

    set("exits", ([
        "south" : __DIR__"guanroad3",
        "east" : __DIR__"jiangdao5",
    ]));

    set("item_desc", ([
        "river" : "��������һҶС�ۣ�Ҳ��(yell)һ�����Ҿ���������\n",
    ]));

    set("outdoors", "jinling");
    setup();
}


/*�ڴ˸�Ǯ�ڶɻ������*/
/*���ȣ��ɴ����˰�������Ǯ������һ��ߺ�ȣ�������һӿ
 * ���룬СС�ɴ�Ƭ�̼��Խ���������εĺ��������ϱ���
 */

void init()
{
         add_action("do_jiaochuan", ({"yell"}) );
}

int do_jiaochuan(string arg)
{
	object ob,ob1;
	if(!arg || (arg!="����" && arg!="boat" )) {
	     if(!arg) arg = " ? ? ? ";	
	     message_vision("$N���Ž��溰��: " + arg + "......\n", this_player());
	     return 1;	
	}
	message_vision("$N���Ž��溰��: ��..��...���ҹ���...\n", this_player());
	if( query("exits/enter") )
		return notify_fail("���Ѿ��������, ������ϴ�(enter).\n");
       set("exits/enter",__DIR__"duchuan");
	message_vision("���Ҷ�$NӦ������...��.....\n", this_player());
	write("�����ˣ�������ϴ�(enter).\n");
	if( ob = find_object(__DIR__"duchuan")) ob->set("exits/out",__DIR__"boat_south");
	call_out("kaichuan_ss",10);
	call_out("daoan_ss",20);
	return 1;
}
void kaichuan_ss()
{
	object ob;
	if( ob = find_object(__DIR__"duchuan")) {
                ob->delete("exits/out");
                message("vision", "�������������壬�Ѵ�����ʻ�����ġ�\n",ob );
	}
       message("vision", "�������������壬�Ѵ�����ʻ�����ġ�\n",this_object());
	delete("exits/enter");
	return;	
}
void daoan_ss()
{
	object ob;
	if( ob = find_object(__DIR__"duchuan")) {
                ob->set("exits/out",__DIR__"boat_north");
                message("vision", "����������壬�����е����������������͹����ϰ���\n",ob );
	}
	return;	
}


