// sanpo7.c
// ɽ��
inherit ROOM;
void create()
{
	set("short","ɽ��");
	set("long",@long
����Ĳ�ľϡ�裬���е�һЩҲû����ɣ����ƿ�ή��������������
ԼԼ���й��ȳ�ζ���ƺ��Ǵ��µ�Ʈ�����ģ��������˸е��ܲ��������
�����Ǿ���֮�أ����ǸϿ��뿪Ϊ�
long);
	set("exits",([
	   "westdown" : __DIR__"treen2",
]));
	set("outdoors", "������");
        setup();
	//replace_program(ROOM);
}
	    	
void init()
{        
     add_action("do_kan","kan");
     add_action("do_climb","climb");
}

int do_kan(string arg)
{
    object me=this_player();

    if(arg=="ɽ��" || arg=="�µ�" || arg=="mountain")
    {
        if(me->query_kar()>random(50))
        {
            tell_object(me,"�µ������������У���һ��ɽ���ƺ�ͦ�⻬������������(climb)��ȥ��\n");
            me->set_temp("mark/climbvine",1);
        }
        else 
           tell_object(me,"�µ������������У�ʲôҲ�����塣\n");
        return 1;
    }
    return 0;
}

int do_climb(string arg)
{
    object me=this_player();
    object ob;

    if(arg=="ɽ��" || arg="vine")
    {
        if(me->query_temp("mark/climbvine",1)==1)
        {
            me->delete_temp("mark/climbvine");
            message_vision("$Nץ��ɽ�٣�������������ȥ��\n",me);
            ob = load_object(__DIR__"sheku");
            me->move(ob);
            message_vision("$N����һ�ݣ�������أ�\n",me);
            return 1;
        }
        else
            return 0;
    }
    return 0;
}

int valid_leave(object me, string dir)
{
    if(this_player()->query_temp("mark/climbvine",1)==1)    
        this_player()->delete_temp("mark/climbvine");
    return 1;
}
