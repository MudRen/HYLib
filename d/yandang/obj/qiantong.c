#include <ansi.h>

inherit ITEM;

void create()
{
        set_name(YEL"ǩͲ"NOR, ({ "qiantong","tong" }) );
        set("long", "һ����ǩͲ,����װ�˼�ʮ��ǩ.�����ҡ(yao)������.\n");
        set("unit", "��");
        set("weight", 700);
        set("no_give",1);
        set("no_get",1);
}

void init()
{
        add_action("do_yao", "yao");
}
int do_yao(string arg)
{
    object me;
	if( !living(this_player()))	return 0;
    if(arg!="qiantong") return 0;
    me=this_player(); 
    if (me->query_temp("oldsix_flag/money")!=1) 
     return notify_fail("���˹���Ц��,ָ��ָ��Ե��,��:��ʩ����ʩһ��!\n");
    me->set_temp("yao",me->query_temp("yao")+1);

    if(me->query_temp("yao")==5)
    {
      me->set_temp("yao",0);
   tell_object(me,"��ǩͲ�е�����һ��ǩ,����ϸ�ذ����ź�!\n");
   clone_object(__DIR__"qian")->move(me);
   me->delete_temp("oldsix_flag/money");
    }
    else
      message_vision("$N�ϵ�ҡ����ǩͲ��\n", me);
   
    return 1; 
}

