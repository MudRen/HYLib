// by dubei

#include <ansi.h>
#include <room.h>

inherit ROOM;

string zhuo(object);
string mu(object);
string bi(object);
string tai(object);

void create()
{
    set("short", BLU "ɽ��"NOR);
    set("long", @LONG
�ⶴ��ʵ��ǳ���в������ɣ��ѵ־�ͷ�����г���һ��ʯ����һ��
ʯ��֮����ޱ��������һ����ʯ���𣬼���һ����Ĺ���������ƺ�
д�����֣�ֻ�ǳ���̦�Σ��ڰ����Ʋ������
LONG
    );

    set("exits", ([
        "out":__DIR__"dongkou",
    ]));
    set("huoshi_count", 2);
    set("item_desc", ([
//        "huoshi" : "����������С���ǿ��Ե�ȼ����֦��\n",
        "zhuo" : (: zhuo :),
        "den" : "��ͨ��ʯ�ʡ�\n",
        "mu" : (: mu :),
        "tai" : (: tai :),
        "bi" : (: bi :),
    ]));

    setup();
}

string zhuo(object me)
{
    me = this_player();
    me->set_temp("temp/looked_zhuo", 1);
    return  "��ͨ��ʯ�������Ϸ���һ�Ի�ʯ��\n";
}

string tai(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "�����������ģ���ʲôҲ���������\n";

    if((int)me->query_skill("force", 1) < 100)
        return  "����������̦�ͻҳ���\n";

    if((int)where->query_temp("temp/qingtai") < 1)
        return  "����������̦�ͻҳ�����̦�����ƺ�����һЩС�֡�\n";
       else
//       me->set_temp("temp/qingtai",1);
        return  "Ĩȥ��̦�ı��Ͽ���һЩС�֡�\n";
}

string bi(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "�����������ģ���ʲôҲ���������\n";

    if((int)me->query_skill("force", 1) < 100)
        return  "����������̦�ͻҳ���\n";

    if((int)where->query_temp("temp/qingtai") < 1)
        return  "����������̦�ͻҳ�����̦�����ƺ�����һЩС�֡�\n";

    me->set_temp("temp/looked_bi", 1);

    return
    "Ĩȥ��̦�ı����ֳ������������ּ��ʻ���ϸ����ʯȴ�Ǽ��������\n"
    "�������ı��л��ɡ�  ���������ֵ���                            \n\n"
    "�ݺὭ����ʮ���أ�ɱ����ܣ��ܾ�Ӣ�ۣ����¸��޿��֣��޿��ͺΣ�\n"
    "Ω������ȣ��Ե�Ϊ�ѡ��غ�����ƽ��һ���ֶ����ɵã��ϼ����ѿ�Ҳ��\n\n"
    "                                                ��ħ�������  \n";
}
string mu(object me)
{
    object where = environment(me);

    if((int)where->query_temp("temp/light") < 100)
        return  "�����������ģ���ʲôҲ���������\n";

    if((int)me->query_temp("temp/looked_bi") < 1)
        return  "���վ�������������˭�ķ�Ĺ��\n";
    else
    {
        me->set_temp("temp/looked_mu", 1);
        me->delete_temp("temp/looked_bi");
        return
        "�Ǹ�ʯ�ѵķ�Ĺ��Ҳ��������ǣ�������λ����������ᣬ�������ʯ\n"
        "������ʬ��֮�ϡ�\n";
    }
}

void init()
{
    add_action("do_use", "use");
    add_action("do_ca", "ca");
    add_action("do_guibai", "guibai");
    add_action("do_move", "move");
    add_action("do_guibai", "kneel");
       add_action("do_na","na");
       add_action("do_zuan","zuan");
}

int do_use(string arg)
{
    object me=this_player(), ob;
    object where = environment(me);

    if((!arg) || (arg != "huoshi"))
        return notify_fail("��Ҫʹ��ʲô��\n");
    if( !(ob=present("ku shuzhi", me)) )
        return notify_fail("��û������֮�\n");

    message_vision("$N��ȼ�˿���֦����Χ��������������\n", me);
    where->add_temp("temp/light", 100);
    destruct(ob);
    return 1;
}
int do_na(string arg)
{
      object me;
      me = this_player();

    if(!me->query_temp("temp/looked_zhuo"))
    return notify_fail("������ʲ�᣿\n");

     if((!arg) || (arg != "huoshi"))
     return notify_fail("��Ҫ��ʲô��\n");
     
     if (query("huoshi_count") > 0) 
     {
         message_vision("$N��ʯ��������һ����ʯ��\n", me);
         add("huoshi_count", -1);
         new(__DIR__"obj/fire")->move(me);
         me->delete_temp("temp/looked_zhuo");
     }
     else
     message_vision("$N������������ʲ��Ҳû�ҵ���\n", me);
     me->delete_temp("temp/looked_zhuo");
     
    
    return 1;
}
int do_ca(string arg)
{
    object me = this_player();
    object where = environment(me);

    if((!arg) || (arg != "qingtai"))
        return notify_fail("��ҪĨȥʲô��\n");

    if((int)where->query_temp("temp/light") < 100)
        return notify_fail("������һ��ʪ��������̦��\n");

    if( ((int)me->query_skill("force", 1)<100) ||
        ((int)me->query_skill("dodge", 1)<100) )
    {
        message_vision("$N����һĨ��̦����֪���ϴ򻬣�һ��������ˤ���ڵأ�\n", me);
        return 0;
    }

    where->set_temp("temp/qingtai", 100);
    message_vision("$NĨȥ�˱��ϵ���̦��¶��������̵�С�֡�\n", me);

    return 1;
}

int do_guibai(string arg)
{
    object me = this_player();
    object where = environment(me);

    if((!arg) || (arg != "mu"))
        return notify_fail("��Ҫ����¹��\n");

    if((int)me->query_temp("temp/looked_mu") < 1)
        return notify_fail("��Ҫ����¹��\n");

    message_vision("$N����һ���񣬲��Խ�����ʯĹ֮ǰ��ݣ������İݡ�\n", me);
    write("���Ȼ����ɽ�������ƺ��и����ڣ�һ��һ�����ߵ�ʯͷ�ƺ��ѳ��ڷ�ס�ˡ�\n");
    me->set_temp("temp/kneel", 1);
    me->delete_temp("temp/looked_mu");

    return 1;
}
int do_move(string arg)
{
     object me = this_player();

   if(!me->query_temp("temp/kneel"))
    return 0;

       if((!arg) || (arg != "stone"))
   return notify_fail("��Ҫ��ʲ�᣿\n");

    if((int)me->query_str()<30)
   return notify_fail("�����������ƾ�ʯ������ͬ���Ѻ���һ����\n");


    message_vision("$N����˫�ڣ���������ʯ�ƿ�һ��С�졣\n", me);
    me->delete_temp("temp/kneel");
    me->set_temp("make/xmove",1);
    return 1;
}
int do_zuan(string arg)
{
     object me = this_player();

   if(!me->query_temp("make/xmove"))
    return 0;

    if((!arg) || (arg != "shifeng"))
   return notify_fail("��Ҫ��ʲ�᣿\n");
 
    me->set_delete("make/xmove");
    me->move(__DIR__"donghou");
    message_vision("$N������������ʯ�������˳�����\n", me);
 
  
    return 1;
}

int valid_leave(object me, string dir)
{
    if((me->query_temp("make/xmove")) && dir=="north")
    {
        me->move(__DIR__"donghou");
        return 1;
    }
	return ::valid_leave(me, dir);
}
