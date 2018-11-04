// This is a room made by wsl.
inherit ROOM;
void create()
{
    set("short", "���");
    set("long",@LONG
����"ˮ��"�ӣ��ߵ��˴��ľ�ͷ��������ǽ�̻Իͣ�ӭ��
��һ����ͷ�������ô���������ɣ���������Ƕ�����ı�ʯ���Ϸ�
�и�˶�����ͷ��Ҳ���ɽ������ɣ�Ρ��׳�ۡ��������Ⱦ޴��ʯ
�ţ���ȴ�ǹ��ŵġ�
LONG
);
        set("exits", ([
                "south" :__DIR__"dadian2",
]));
    set("qiao",1);
    setup();
}
void init()
{
        add_action("do_look","look");
        add_action("do_climb","climb");
        add_action("do_qiao","qiao");
        add_action("do_jump","jump");
}
int do_look(string arg)
{
        object me=this_player();
        if (!arg)       return 0;
//        if (!me->query_temp("killer")) return 0;
//        if (!me->query_temp("climb")) return 0;
        switch (arg){
                case "��ͷ":    if (query("qiao"))
                                write("ϸ�������ͷ�����۾��������ƺ���Щ�촦��\n");
                                else
                                write("ϸ�������ͷ���ŷ�����ͷ�������������ӡ�\n");
                        return 1;
                case "ʯ��":    write("ʯ�����������Ż���ȴ������һ˿��϶���Ż�����\n����������֪������ʲô�õġ�\n");
                        me->set_temp("look",1); 
                return 1;
        }
        return 0;
}
int do_climb(string arg)
{
        object me=this_player();
        object weapon;
        if(!arg)        return 0;
        if(!me->query_temp("look")) return 0;
        if(arg != "����")       return notify_fail("��Ҫ������ѽ��\n");
        if(me->query_temp("chan")) return notify_fail("���Ѿ�����ͷ���ˡ�\n");
        if (!objectp(weapon = me->query_temp("weapon"))) return notify_fail("���������ģ�����ô��ѽ��\n");
        if (weapon->query("skill_type")!="whip")        return notify_fail("�㻹����������ʲô�ģ�Ҳ���������ȥŶ��\n");
        message_vision("$Nʹ��"+weapon->query("name")+"������һ�ף����������ϡ�\nȻ��$Nʩչ�Ṧ����������ͷ�ϡ�\n",me);
        me->set_temp("chan",1);
                return 1;
}
int do_qiao(string arg)
{
        object me=this_player();
        object weapon,ob;
        if(!arg)        return 0;
        if(!me->query_temp("chan")) return notify_fail("�㹻���š�\n");
        if(!query("qiao")) return notify_fail("�㻹Ҫ��ʲô��\n");
        if(arg != "����")       return notify_fail("������ʲô�\n");
        if (!objectp(weapon = me->query_temp("weapon"))) return notify_fail("���ְ���Ҳ����Щʲô��������õ�Ŷ��\n");
        if (weapon->query("skill_type")!="throwing")      return notify_fail("���������"+weapon->query("name")+"�����˼��£��ŷ���������������ʹҲ��\n");
        message_vision("$N�ͳ�һ��"+weapon->query("name")+",ʹ��������������\n$N�����̵������������ˣ���������������˶������ۡ�\n",me);
        message_vision("���ۺ�����Է�(pushin)��ʲô�ط�ȥ��\n",me);
        ob=new(__DIR__"obj/longzhu.c");
        if (!ob->move(me))
                ob->move(this_object());
        ob=new(__DIR__"obj/longzhu.c");
        if (!ob->move(me))
                ob->move(this_object());
        set("qiao",0);
        return 1;
}
int do_jump(string arg)
{
        object me=this_player();
        if(!arg)        return 0;
        if(!me->query_temp("chan")) return 0;
        message_vision("$Nһ������������������\n",me);
        me->delete_temp("chan");
        return 1;
}
void open_door(object ob,int i)
{
    object room;
    if (!ob || environment(ob)!=this_object())  return;
    if (i<10)
    {
    tell_room(this_object(),"ʯ�ż��ҵ�����һ�£�����...��...��...��\n");
    call_out("open_door",10,ob,i+1);
    return;
    }
    tell_room(this_object(),"���ϵ�ʯ��ת����һȦ��ֻ��ʯ���͵������߷ֿ���");
    if (!room=find_object(__DIR__"shidao2"))
        room=load_object(__DIR__"shidao2");
    message_vision("$Nվ�����ȣ���һ��ǿ����������˽�ȥ��\n",ob);
    ob->move(room);
    ob->unconcious();
}

