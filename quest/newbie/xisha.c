//[lsg 1999//11/25]
#include <ansi.h>;
inherit ROOM;

void create()
{
        set("short", "ϴɳ");
        set("long", @LONG
  ��������Ұ��һ��ϴɳ������˵�ϰ���������ģ��������ֵģ�
ͦ���˷�Ц�������������(xi sha)��Щ����Ͱ�����
LONG
        );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);

        set("exits", ([
        "north" : "/d/city/jiaowai9",
                
]));
        setup();
}

void init()
{
        add_action("do_xi","xi");
        add_action("do_ban","dazuo");
        add_action("do_ban","du");
        add_action("do_ban","study");

}

int do_ban()
{
        write ("������˼�ϴɳ����\n");
        return 1;
}
int do_xi(string arg)
{
        object me = this_player();
        int bonus,exp,pot;
        object mon;

        if((int)(me->query("combat_exp")) > 15000)
              return notify_fail("�Թԣ���ľ���̫���ˣ�ȥ��ı��·�ɡ�\n");
        if (!arg)
              return notify_fail("��Ҫϴʲô��\n");
        if (arg != "sha")
              return notify_fail("����ֻ��ϴɳ�� ��������\n");
if (me->is_busy())
return notify_fail("����æ����!\n");
        if( (int)me->query_temp("sha") ) 
              return notify_fail("���Ѿ��ڿ�ʼϴ�ˡ�\n");
        if ((int)(me->query("qi")) < 26)        
              return notify_fail(RED"��̫�ͣ���ϴ���İ�С���͵����㻹����Ϣһ�°ɡ�\n");
        if ((int)(me->query("jing")) < 26)        
              return notify_fail(RED"��̫�ͣ���ϴ���İ�С���͵����㻹����Ϣһ�°ɡ�\n");
        message_vision("
$N��˫�����ð�Ű��ݵ�ˮ�У���ʼϴɳ��\n\n",me);
        me->set_temp("sha",1);
        me->add("qi",-10);
me->start_busy(8);
        call_out("del_sha", 8, me, mon, bonus, exp, pot);
        return 1;
}

void del_sha(object me, object mon, int bonus, int exp, int pot)
{
if (!me) return;
        me->delete_temp("sha");
        if (random (10) < 3)
{
       message_vision(HIR"
$N����ͷ������ϸ��ϴ�Ž�ɳ��ֱ�۵���ͷ�󺹣���ɫ�԰�,\n
һ��С�ġ��ˡ���һ������ϴɳ����ð׸��ˣ��ϰ�ûҪ����ɳ����õ��ˡ�\n"NOR,me);
            me->start_busy(4);
        return ;
}
        else
{
        exp = 2 + random(8);
        pot = 1 + random(4);
        message_vision(HIC"
   $N��ͷ������ϸ��ϴ�Ž�ɳ��˿�����Ҵ��⡣\n
����֮������ϴ����" + chinese_number(exp) + "���ɳ��\n\n"NOR
  HIB"�ϰ����˹�����������ͷ��˳�ָ�$Nһ�����ӣ�˵�������ţ��á����ٽ���������\n"NOR,me);
        bonus = (int) me->query("combat_exp");
        bonus += exp;
        me->set("combat_exp", bonus);
        bonus = (int) me->query("potential");
        bonus += exp;
        me->set("potential", bonus);
        me->receive_damage ("qi",8 + random(10));
        me->receive_damage ("jing",8 + random(10));
        me->receive_wound ("qi",1);
        me->receive_wound ("jing",1);
        mon = new("/clone/money/silver");
        mon->set_amount(exp);
        mon->move(me);
        me->start_busy(4);
        return;
}
}
