//cool980727


inherit ROOM;
void create()
{
        set("short", "�о���");
        set("long", @LONG
����������ɮ���о��ĵط���һ����ȥ���������������ˣ��о�
������������еĵͳ��������еļ������٣��м�����ҡ�������Ľ�
�������������Ҹ��ط�����������������ʼ�����ǰ�������ౡ
����С�ᾭ��(book),�Թ�����á�
LONG);
        set("exits", ([
                "north" : __DIR__"baodian",
        ]));
 
         set("no_fight", 1);
 
        setup();
}
#include "book.c";

void init()
{
       add_action("do_song", "songjing");
       add_action("do_song", "dujing");
       add_action("do_look", "look");
       add_action("do_halt", "ting");
	   add_action("do_zuo", "sit");
       add_action("do_zuo", "zuo");
}
int do_look(string arg)
{
	object me = this_player();
    if (!arg) return 0;
	if (arg == "book") {
            if (me->query_skill("buddhism",1)<100)
			{
            write("��Щ���Ǿ���������̫������ˡ�\n");
			} else {
			write("��Щ���Ǿ��飬�ֳ�С���ӣ�����Զ�(songjing)����������Լ�\n"
			+"�ķ�ѧ֪ʶ \n"
            +"����վ�-��1��(jingang-jing1)    ����վ�-��2��(jingang-jing2)\n"
			+"����վ�-��3��(jingang-jing3)    ����վ�-��4��(jingang-jing4)\n"
			+"����վ�-��5��(jingang-jing5)    ����վ�-��6��(jingang-jing6)\n"
			+"����վ�-��7��(jingang-jing7)    ����վ�-��8��(jingang-jing8)\n"
			+"����վ�-��9��(jingang-jing9)    ����վ�-��10��(jingang-jing10)\n"
			+"����վ�-��11��(jingang-jing11)  ����վ�-��12��(jingang-jing12)\n"
            +"����վ�-��13��(jingang-jing13)  ����վ�-��14��(jingang-jing14)\n"
			+"����վ�-��15��(jingang-jing15)  ����վ�-��16��(jingang-jing16)\n"
			+"�������������ľ���(xin-jing)\n"
             +"��������ˣ�����ͣ(ting)�£���Ϣ�£�����ͷ����\n");
			me->set_temp("book_list", 1);
		    }
			return 1;
	       		   }		
}
int do_zuo(string arg)
{

	if (arg) return notify_fail("����ûʲô�����ģ������ϰ�\n");	
	
	if (this_player()->query("class")!="bonze")
		return notify_fail("�㲻�ǳ����ˣ��������������о���\n");	
	
	if (this_player()->query_temp("book_sit"))
		return notify_fail("���Ѿ����ڵ����ˡ�\n");	
			
	this_player()->set_temp("book_sit", 1);
	return notify_fail("�����˸��յ��������¡�\n");	
}

int do_halt()
{    
    object me = this_player();
    if (find_call_out("sing_stage") < 0) return 0;
//	me->receive_damage("jing",(int)me->query_skill("buddhism",1)/3);
	me->receive_damage("jing", (int)me->query_skill("buddhism",1)/4);
    message_vision(HIR"\n$N�������Щ���ˣ�ͣ������Ϣ�¡�\n"NOR,me);
    remove_call_out("sing_stage");
    return 1;
}

int do_song(string arg)
{
       object me, ob; 
       int i = sizeof(book);
       int stage;

       stage = 0;
       me = this_player();
       ob = this_object();
	   if (me->query("class")!="bonze") return notify_fail("�㲻�ǳ����ˣ��������������о���\n");
       if (!me->query_temp("book_list")) return notify_fail("�������������������Ϳ�ʼ����\n"); 
	   if(!arg) return notify_fail("�����ʲô����\n");
	   if (!me->query_temp("book_sit")) return notify_fail("�и��ԣ�վ�Ŷ���\n"); 
	   if (find_call_out("sing_stage") >= 0) return notify_fail("����ͬʱ������������\n");
       if(!arg) return notify_fail("�����ʲô����\n");
	   if (me->query("jing")<100 ||me->query("jing")<200)
             return notify_fail("�����ھ���������������Ϣ��Ϣ�ٶ��ɣ�\n");
        while (i--) if (arg == book[i]["name"]) break;
        if (i<0) return notify_fail("����û��������ľ���\n");
        if(me->is_busy())
           return notify_fail("����æ���ء�\n");
		tell_object(me,HIC"��������ӣ������е���\n"
                      +"��������΢� ��ǧ��������� \n"
                      +"�ҽ���ŵ��ܳ� Ը��������ʵ�� \n"NOR);   
        message_vision(HIW "$N���ˡ���������ľ�㣬�������飬��ʼ�������ɶ���������\n\n"NOR, me);
              
      call_out("sing_stage", 2, me, stage, i, sizeof(book[i]["context"]));
      return 1;
}

void sing_stage(object me, int stage, int i, int size)
{
   if(stage < size) {
// message_vision(book[i]["context"][stage], me);
   tell_object(me,book[i]["context"][stage]);
   me->start_busy(1);
   call_out("sing_stage", 1, me, ++stage, i, size);
   }
else {
      message_vision(HIW"\n����һ�ᣬ$N��������С�����������š��ϡ���һ���������죬�漴��Ȼ������\n"NOR,me);
      if (me->query_skill("buddhism",1) > 300 ){
	    tell_object(me,"����ö�����ԣ��о������������ķ�ѧ��Ϊ�ˡ�\n");
       } else {
//	    me->receive_damage("jing",(int)me->query_skill("buddhism",1)/2);
		me->receive_damage("jing", (int)me->query_skill("buddhism",1)/3);
        me->improve_skill("buddhism", (int)me->query_int()/3+random((int)me->query_int()/2)); 
		tell_object(me,"����Щƣ�ۣ��������о��У��Է���������\n");  
	   }
      }
}
int valid_leave(object me, string dir)
{

	me->delete_temp("book_sit");
	me->delete_temp("book_list");
	return ::valid_leave(me, dir);
}
