inherit ROOM;

void check_trigger();
void on_board();
void arrive();
void close_passage();
void reset();
int do_yell(string arg);

void create()
{
	set("short", "��������");
	set("long", @LONG
��������Ҳ���൱���֣��Ա����ɿ�������һ����ֱ�Ĺٵ�
ֱͨ�������˵���紾�ӣ�·�Լ��������������������Ҷ���һ
����ġ��ơ���ӭ��Ʈ�εΪ׳�ۡ�Ҳ�в���С����·����
����ѱ棬ȴҲ����ʢ����ȴ��
LONG
	);

    set("exits", ([
		"northwest" : "/d/nanyang/yidao3",
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
	if( ob = find_object(__DIR__"duchuan")) ob->set("exits/out",__DIR__"boat_north");
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
                ob->set("exits/out",__DIR__"boat_south");
                message("vision", "����������壬�����е����������������͹����ϰ���\n",ob );
	}
	return;	
}



