// demongorgon.c
#include <ansi.h>
inherit NPC;
void create()
{
     int skill;
        set_name( HIW "����֮��" NOR, ({ "demogorgon" }) );
        set("long",
                "����֮�������ư���վ������ǰ�����ߴ��������һ��������Ϣ��\n"
                "����ɱ����ѹ���㼸����������������������ƺ���һ�������ڸ�\n"
                "���㣺�� �� �� ������\n");
        set("age", 7006);
        set("pursuer", 1);
    set("attitude", "peaceful");
        set("max_jing", 5000);
         set("max_qi", 500000);
        set("max_jingli", 9999);
        set("jingli", 9999);
        set("max_neili", 100000);
          set("neili", 8000000);
         set("demogorgon",1);
         set("str", 100);
        set("dex", 100+random(100));
     set("title",HIR "ɱ��ħ" NOR);
        set("int", 100);
        set("no_suck", 1);
        set("con", 100);
        set("jiali",50000);
        set("kar", 0);
        set("per", 0);
        skill=400+random(1000);
         set("combat_exp", 200000000);
        set_skill("staff", skill/2);
        set_skill("unarmed", skill);
        set_skill("parry", skill);
        set_skill("dodge", skill);
        set_temp("apply/attack", 400);
        set_temp("apply/defense", 200);
        set_temp("apply/damage", 1200);
        set("chat_chance_combat", 10);
        set_temp("apply/parry", 300);
        set("chat_msg_combat", ({
           (: command("wield staff") :),
                CYN "����֮��˵��С���˵��õĲ�ѧ��ѧ�˸������縺�������У�\n" NOR,
                CYN "����֮����������춼�л쵰�������縺��������������Ҳ˯���ã�\n" NOR,
           (: command("unwield staff") :),
        }) );


        setup();
        set("water",max_water_capacity());
        set("food",max_food_capacity());
        carry_object(__DIR__"obj/demon_staff")->wield();
//        carry_object("/clone/misc/red_cloth")->wear();
}
void start_shutdown()
{
        if( geteuid(previous_object()) != ROOT_UID ) return;
        set_temp("time",-10000);
        message("system",
                HIR "\n����������д���һ����µ����� ....\n\n"
                HIW     "����֮��" HIR "����������������ȵ���\n\n"
                        "\t\tȫ �� �� �� �� �� �� �� �� �� ��\n\n"
                        "\t\t�������������ڰ��ҵ�ͷ­������ ��\n\n"
                        "\t\t�� Ȼ �� �� ..... �� .. �� ��\n\n" NOR,
                users() );
        call_out("countdown", 60, 3);
}
protected void countdown(int min)
{
        min--;
        if( min ) {
                message("system",
                        HIW "\n����֮��" HIR "����������������ȵ���\n\n"
                                "\t\t���ǻ���" + chinese_number(min) + "���ӵ�ʱ�佻���ҵ�ͷ­��\n\n"
                                "\t\t������Ҫ�������ġ��͡������ҡ����������ϡ��ɡ���\n\n" NOR,
                        users() );
                call_out("countdown", 60, min);
        } else {
                message("system",
                        HIW "\n����֮��" HIR "����������������ȵ���\n\n"
                                "\t\t�ɺ�.....���ǿɺ�....\n\n"
                                "\t\t���찡�� ��ذ���  ���󰡡�  ��������\n\n" NOR,
                        users() );
                call_out("do_shutdown", 3);
        }
}
protected void do_shutdown()
{
        object *ob;
        int i;
        message("system",
                HIW "\n\n����֮��" HIR "����������������ȵ���\n\n"
                HIW "\t\tͨ ͨ �� �� һ �� �� �� �� �� �������� ��\n\n"
                HIR "\t\t����һ�ϣ�������̱��Ѫ�죬��....����ǰ��һ�ж����Ѫ��...\n\n"
                        "\t\t���е�һ�ж���˲�������....\n\n"
                        "\t\tȻ�������ǰ��һƬ�ڰ�....��ֹ���ĺڰ�....\n\n" NOR,
                users() );
        ob = users();
        for(i=0; i<sizeof(ob); i++) {
                ob[i]->save();
        }
     NATURE_D->auto_shutdown(1);
}

void unconcious()
{
        object ob;
        if( !ob = query_temp("last_damage_from") )
                ob = this_player(1);
        if( !ob ) return;
        message("vision",
                HIR "\n\n������һ�������ߺޡ����֡���Ұ�ް���������쳹������ա�\n\n"
                HIW "����֮��" HIR "˻�Ƶغ������ɶ��" + ob->name(1) + "����һ���ᱨ��ġ�����\n\n"
                        "Ȼ��һ����ɫ�����Х�������ƶˣ�����ָֻ���������\n\n" NOR,
          environment() );
        destruct(this_object());
}

void die()
{
   unconcious();
}

int heal_up()
{
        if (!living(this_object()))    return ::heal_up() + 1;
        if( environment() && !is_fighting() ) {
                  if (query_temp("time")>5){
                        call_out("leave", 1);
                        return 1;
                }
                if (query_temp("time")%3)
                        message_vision("$N"+"����̽��������������Ҫɱ���ˡ�\n",this_object());
        add_temp("time",1);
        }
        return ::heal_up() + 1;
}
void leave()
{
        message_vision("$N"+GRN+"���ҿ��˿�������Ŀ���Ѿ������ˣ����������󲽣�ͷҲ���ص����ˡ�\n"+NOR,this_object());
        this_object()->move(VOID_OB);
        destruct(this_object());
}
void killed_enemy(object obj)
{
    if (query("kill_ob")) delete("demogorgon");
       call_out("leave",1);
}
void init()
{
    ::init();
    add_action("do_go","go");
    add_action("do_kill","kill");
    add_action("do_kill","hit");
    add_action("do_kill","fight");
}

int do_go(string arg)
{
        mapping exit;
        if( !mapp(exit = environment()->query("exits")) || undefinedp(exit[arg]) )
                return 0;
        if (is_killing(this_player()))
                if (random(10)<=2) {
                        message_vision(YEL "$N���Ʋ��ã�ת��Ҫ�ߣ���$n"+YEL+"һ��������ǰ�����ߣ�û��ô���ף�\n"NOR, this_player(), this_object());
                        return 1;
                        }
        return 0;
}

int do_kill(string arg)
{
    if (!arg) return 0;
   if (id(arg))
  {
    set("kill_ob",1);
    if (!is_killing(this_player()))
    message_vision("$N"+CYN+"��ݺݵص���$nһ�ۣ�����Ҵ�������ˣ�\n" NOR,this_object(),this_player());
    set("eff_qi",query("max_qi"));
    set("eff_jing",query("max_jing"));
    set("jing",query("max_jing"));
    set("qi",query("max_qi"));
    add("neili",1000);
    kill_ob(this_player());
   }
    return 0;
}
