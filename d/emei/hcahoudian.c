//Room: hcahoudian.c �����ֺ��
//Date: Oct. 2 1997 by That
#include <ansi.h>

inherit ROOM;
void do_chat();

void create()
{
      set("short","�����ֺ��");
      set("long",@LONG
���Ƕ���ɽ�����ֵĺ��Ƕ����������˴��̵��ӹ���ĵط������﹩
��һ���������������Կ�ǽ���ż���̫ʦ�Σ����Ϸ��ż������š���������
���򼸸�Ů���Ӵ����书��
LONG);
      set("objects", ([
           "quest/menpaijob/emei/miejue" : 1,
      ]));
      set("no_get_from", 1);
      set("no_get", 1);
      set("no_steal", 1);
      set("no_clean_up", 0);
      set("exits",([ /* sizeof() == 1 */
          "north"   : __DIR__"hcadadian", 
      ]));
      setup();
//      replace_program(ROOM);
}

void init()
{
    add_action("do_swear",  ({ "qishi", "fashi" }));
    add_action("do_huzhuo",  ({ "huzhuo" }));
    add_action("do_nod",  ({ "nod" }));
}

int do_swear()
{
    object ob, me = this_player();
    object where = environment(me);
    if( !(ob = present("miejue shitai", where) ) )
        return 0;
    if( me->query_temp("jiuyin/emei") < 5 )
        return 0;
    if( me->query("gender") == "Ů��" )
        message_vision("$N˵����СŮ��" + me->query("name") + "�������ģ��պ�������ħ�̽������޼�����ͽ�Ĵ氮Ľ��
����������ɷ򸾣�������ĸ���ڵ��£�ʬ�ǲ��ð��ȣ���ʦ�����ʦ̫�س�����
����һ����ҹ�����������������¶�Ů�����Ӵ���Ϊū��Ů������Ϊ潡�\n", me);
    else
        tell_room(where, me->query("name")+"˵��������" + me->query("name") + "һ��Ҫʵ��ʦ̫������Ը�����������ӣ�
�⸴����ɽ�ӣ��������������Ⱥ�ף��ǹ����֡��䵱����Ϊ��ԭ�����еĵ�һ���ɡ�
��Υ����������������򽣴�����������֮�ء�\n");
    tell_room(where, "���ʦ̫����¶��һ˿Ц�ݡ�\n");
    me->set_temp("jiuyin/emei", 6);
    tell_room(where, "���ʦ̫˵������Ů������������֮ǰ���͹�����������һ����������д�˱������书��
��Ҫ���ֱ���ڵ���֮�С��������вص����Ǳ������˵���Ϊ������������Ϊ�պ����˵�
�����б��飬�����������ӣ�ɱ�����ӻʵۡ����콣�вص�������ѧ���ţ�������Ϊ����
�ģ�����һ���������澭����һ��������ʮ�����Ʒ����塯����������ϰ�ý����书����
���е���Ϊ�������\n");
    tell_room(where, "���ʦ̫˵������ȡ�������������콣�����������һ��ִ����һ�ֳֽ�������������
�Ե������(huzhuo)�����������㼴ͬʱ���ۣ�����ȡ�����ڵ���ͽ����е����š�����
ȡ�����ŵ�Ψһ���ţ��Ǳ���������Ҳ�Ӵ˻��ˡ����ס��ô��\n");
    return 1;    
}

int do_nod()
{
    object me=this_player();
    if( me->query_temp("jiuyin/emei") != 6 )
        return 0;
    me->set_temp("jiuyin/emei", 7);
    message_vision("$Nֻ���û�����Ѫ���ڣ�һ�ɺ�Ȼ�����������ؽ�\n", me);
    me->set("shen", me->query("combat_exp"));
    return 0;
}

int do_huzhuo()
{
    object ob, me=this_player();
    object ob0, ob1, ob2, where = environment(me);
    if( me->query_temp("jiuyin/emei") < 6 )
        return 0;
    if( !(ob1 = present("sky sword", me)) )
        return notify_fail("������û�ж��Ҹ������ֵ������콣��\n");
    if( !(ob2 = present("tulong dao", me)) )
{
if (me->query("blade_get"))
{
me->delete("blade_get");
}

        return notify_fail("������û�����ߵ��������ֵ�����������\n");
}
    if( !ob1->query_autoload() )
return notify_fail("��ѽ�������Ʒ!��Ʒ�ڶ���ɽ������\n");
    if( !ob2->query_autoload() )
{
if (me->query("blade_get"))
{
me->delete("blade_get");
}
return notify_fail("��ѵ�������Ʒ!��Ʒ�����ߵ�������\n");
}

    if( me->query_temp("jiuyin/emei") != 7 )
        return notify_fail("���Ӧ�����ʦ̫��Ҫ������\n");
    if (this_object()->query("alrea"))
    return notify_fail("�Ѿ����˰���������!\n");
    if( !(ob = present("miejue shitai", where) ) )
        return notify_fail("���ʦ̫�������������ȱ���������\n");
    message_vision("ֻ��$Nһ��ִ����һ�ֳֽ���������������������
ֻ�������ꡯ��һ�����죬�����Ѿ�����˫�������������콣�ʹ���ʧ�ˡ�\n", me);
    destruct(ob1);
    destruct(ob2);
    me->delete("blade_get");
    message_vision("���ʦ̫�Ӷϵ��Ͻ���ȡ���˼��Ų������˼��ۣ��ó�һ�Ų�������$N��\n", me);
    if( me->query_skill("xianglong-zhang", 1) > 0)
        tell_room(where, "���ʦ̫˵��������ʮ�������Ѿ�ѧ�ˣ��������ٳ�ƪ�����ȥѧ�ɡ�\n");
    else
        tell_room(where, "���ʦ̫˵���������ѧ·���뽵��ʮ���Ƶĸ��������������Ȿ�����ٳ�ƪ�����ȥѧ�ɡ�\n");
    tell_room(where, "���ʦ̫˵���������ٵ�һ���ĵ����ơ����Ϊ����־ʿ�������鴫��������Ҫ������������²��\n");
    me->delete_temp("jiuyin/emei");
    me->set("jiuyin/emei", 1);
    ob0 = new("/clone/book/jiuyin-sucheng");
    ob0->move(me);
    this_object()->set("alrea",1);
    message("channel:rumor", MAG"��ҥ�ԡ�ĳ�ˣ�"+me->query("name")+"�õ������ٳ�ƪ����\n"NOR, users());
    return 1;
}
