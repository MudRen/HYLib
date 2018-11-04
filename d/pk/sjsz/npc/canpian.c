//Cracked by Kafei
// canpian
// used to improve tjsg and hunyuan-yiqi over 200
// -chu@xkx

#include <ansi.h>
#include <weapon.h>

inherit ITEM;
inherit F_UNIQUE;

int do_dun(string arg);
int do_jie(string arg);

void create()
{
    set_name(YEL "�����񹦲�ƪ" NOR, ({"canpian", "book"}));
    set_weight(100);
    if (clonep())
        set_default_object(__FILE__);
    else {
        set("unit", "��");
        set("long", "�����䵱����ʦ���������˱�¼�Ĳ��־����񹦡�\n");
        set("material", "paper");
        set("value", 1000000000);
                set("skill", ([
                        "name": "jiuyang-shengong",        // name of the skill
                        "exp_required": 10000000,      // minimum combat experience required
                        "jing_cost":    300,     // jing cost every time study this
                        "difficulty":   100,     // the base int to learn this skill
                        "max_skill":    100      // the maximum level you can learn
                ]) );
    }
}

int init()
{
    add_action("do_canwu", "canwu");
    return 1;
}

int do_canwu(string arg)
{
    object player = this_player();
    object target, obj=this_object(), env=environment(player);
    string my_skill, your_skill;
    int my_lvl, your_lvl;

    if (!arg) return notify_fail("��Ҫ��˭һ�����?\n");
    target = present(arg, env);
    if (!objectp(target))  return notify_fail("��Ҫ��˭һ�����?\n");
    if (!userp(target))    return notify_fail("��ֻ�ܸ����һ�����\n");
    if (player->is_busy()) return notify_fail("����æ���ء�\n");
    
    my_lvl = player->query_skill("taiji-shengong", 1);
    your_lvl = player->query_skill("hunyuan-yiqi", 1);
    if (my_lvl < 200 && your_lvl < 200) 
        return notify_fail("���̫���񹦻��߻�Ԫһ���������ߣ��޷�����\n");
    if (my_lvl >= 200) {
        my_skill = "taiji-shengong";
        your_skill = "hunyuan-yiqi";
        your_lvl = target->query_skill("hunyuan-yiqi", 1);
    }else {
        my_lvl = your_lvl;
        your_lvl = target->query_skill("taiji-shengong", 1);
        my_skill = "hunyuan-yiqi";
        your_skill = "taiji-shengong";
    }
    if (your_lvl < my_lvl-10)
        return notify_fail(target->name(1)+"�ı����ڹ�Զѷ���㣬�Ѳ��ܰ�������ˡ�\n");
    if (player->query("jing") < 1000)
        return notify_fail("�㾫�񲻼ã�������˵������ˡ�\n");
    if (target->query("jing") < 1000)
        return notify_fail("������"+target->name(1)+"����й�"+
                to_chinese(your_skill)+"�����⣬���˼�û����ɵĲ����㡣\n");
    message_vision("$N�ó������񹦲�ƪ����$n�໥����˫����������\n",
        player, target);

    if (wizardp(player)) {
        tell_object(player, sprintf("my_skill = %s/%d, yourskill=%s/%d\n",
            my_skill, my_lvl, your_skill, your_lvl));
        tell_object(player, "valid_learn() returns "+
            SKILL_D(my_skill)->valid_learn(player)+"\n");
    } 

    if (wizardp(target)) {
        tell_object(target, sprintf("my_skill = %s/%d, yourskill=%s/%d\n",
            my_skill, my_lvl, your_skill, your_lvl));
        tell_object(target, "valid_learn() returns "+
                SKILL_D(your_skill)->valid_learn(target)+"\n");
    } 

    player->add("jing", -1000); 
    target->add("jing", -500);

    if (SKILL_D(my_skill)->valid_learn(player))    {
        player->improve_skill(my_skill, 200);
        if (SKILL_D(your_skill)->valid_learn(target))  target->improve_skill(your_skill, 80);
        return 1;
    }
    return 0;
}
