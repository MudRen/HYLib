#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�����", ({ "li banxian", "li" , "banxian"}) );
        set("long",
"������Ǹ��׷�ͯ�յ����ˣ��������ˣ��������������[����ʦ]�������\n");
        set("title", BLU"�����"NOR);
        set("attitude", "peaceful");
        set("combat_exp",4000000);
        set("str",60);
        set("per",10);
        set("int",80);
        set("force_factor", 100);
        set("max_force",5000);
        set("force",5000);
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu-bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing-diaoshou",200);
        set_skill("lingshe-zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu-bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe-zhangfa");
        map_skill("unarmed", "shexing-diaoshou");
        map_skill("staff", "lingshe-zhangfa");
        
        set("inquiry", ([
                "����ʦ��¼"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
                "��ʦ"          :"������ڱ���ʦ���˰ɡ�\n",
                "��ʦ��¼"          :"Ҫ������ǰ�����й�һ����ʦʦ�ŵĻ������ʦ���ɲ�Ը����������Ĺ���\n",
                "����ʦ"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
                "����¼"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
        ]) );
        setup();


}
int accept_object(object who, object ob)
{
        int kar, per;

        if (ob->query("money_id") && ob->value() >= 2000) 
        {
                message_vision("����ɶ���$N������һ��\n", who);
                per = who->query("per");
                kar = who->query("kar");
                if (per > 20) {
                        write("����ɾ�����˵������" + RANK_D->query_respect(who) + "��ò���ã���ͥ������������Բ��"); 
                        if (kar > 20) write("���˸���֮��Ҳ����\n");
                        else if (kar >= 17) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("��ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else if (per >= 17) {
                        write("�����������ɤ�ӣ�˵������" + RANK_D->query_respect(who) + "��ò������֮�ʣ�"); 
                        if (kar > 20) write("һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("һ������ƽƽ��Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("������ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else if (per >= 13) {
                        write("������е���ǿ��˵������" + RANK_D->query_respect(who) + "��òƽƽ����Ҳ������������֮�ʣ�");
                        if (kar > 20) write("ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("һ��Ҳ������ƽƽ��ֻ�������ȥ����\n");
                        else if (kar >= 13) write("�Ϳ�ϧ��ײ��С�ˡ���\n");
                        else write("�����ù�˵�ͷ�����¿�ҪС���ˣ���\n");
                        return 1;
                }
                else {
                        write("����ɺ�����˵������" + RANK_D->query_respect(who) + "���Ųλ��ӡ�÷�����");
                        if (kar > 20) write("������ǰ��һ���������£�һ���󸻴�������ࡣ��\n");
                        else if (kar >= 17) write("������Щ������Ҳ�����ȥ�ˡ���\n");
                        else if (kar >= 13) write("�������һ������������С�ˡ���\n");
                        else write("��õ�ù������Ѫ��֮�֣���\n");
                        return 1;
                }
        }
        return 0;
}


int accept_fight(object me)
{
        command("say �����˵���㻹������ҹ��С�");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me= this_player();
        if (arg != "��ʦ��¼") 
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query("betrayer",) < 1) 
                return notify_fail("���ѹ�ʦô��\n");
        if (me->query("banshi") > 2) 
                return notify_fail("�����ʦ�����Ѿ�����3���ˣ�\n");

       if ( me->query("banshi") > 2)
           {
               message_vision("�����ʦ�����Ѿ�����3���ˣ���\n", this_object(), me);
                   return 1;
           }
me->save();
if ((int)me->query("combat_exp") > 500000)
{
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>1)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
}
        message_vision(MAG"$N�����˵��ϣ���ʼ��ڱ���ʦ�ŵ����£����ѽ��������ڡ�����\n\n"NOR,me);
        me->add("betrayer",-1);
        me->add("banshi", 1);
//        me->add("banshi",1);
        me->set("title","��ͨ����");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
        me->start_busy(2);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}

