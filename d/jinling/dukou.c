//jinling  dukou.c
inherit ROOM;

void create()
{
        set("short", "�����ɿ�");
        set("long", @LONG
�����ǳ����ɿڣ���ϵ��������еĽ�ͨ�������̷����ﲻ������һ��
�������ڡ����������������ȥxxx��������ũ�򾭳��������ֵ��߲��˵�
�������������м�ֻС�ۣ�ֻҪ�㺰(yell)һ���������������Ǿͻ�Ѵ�
ʻ����
LONG
        );
        set("exits", ([/* sizeof() == 4 */
           "south" : __DIR__"yuhuatai",

]));
 set("outdoors", "jinling");

        set("no_clean_up", 0);

        setup();
   //     replace_program(ROOM);
}
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
       set("exits/enter",__DIR__"boat");
	message_vision("���Ҷ�$NӦ������...��.....\n", this_player());
	write("�����ˣ�������ϴ�(enter).\n");
	if( ob = find_object(__DIR__"boat")) ob->set("exits/out",__DIR__"jiangbei");
	call_out("kaichuan_nn",10);
	call_out("daoan_nn",20);
	return 1;
}
void kaichuan_nn()
{
	object ob;
	if( ob = find_object(__DIR__"boat")) {
                ob->delete("exits/out");
                message("vision", "�������������壬�Ѵ�����ʻ�����ġ�\n",ob );
	}
       message("vision", "�������������壬�Ѵ�����ʻ�����ġ�\n",this_object());
	delete("exits/enter");
	return;	
}
void daoan_nn()
{
	object ob;
	if( ob = find_object(__DIR__"boat")) {
                ob->set("exits/out",__DIR__"jiangbei");
                message("vision", "����������壬�����е����������������͹����ϰ���\n",ob );
	}
	return;	
}

