#include <ansi.h>
inherit NPC;
void create()
{
        set_name("����ͷ", ({ "wang xunbu", "wang" , "xunbu"}) );
        set("long",
"����ͷ�Ǹ����ǵĲ�ͷ���������ˣ��������������[ȡ��ͨ��]�������\n");
        set("title", BLU"��������"NOR);
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
        
//        set("inquiry", ([
//                "����ʦ��¼"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
//                "��ʦ"          :"������ڱ���ʦ���˰ɡ�\n",
//                "��ʦ��¼"          :"Ҫ������ǰ�����й�һ����ʦʦ�ŵĻ������ʦ���ɲ�Ը����������Ĺ���\n",
//                "����ʦ"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
//                "����¼"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
//        ]) );
        setup();


}
int accept_fight(object me)
{
        command("say ����ͷ˵���㻹������ҹ��С�");
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
        if (arg != "ͨ����¼") 
                return notify_fail("��Ҫ��ʲô��\n");
//      call snowfly->apply_condition("killer",0);
        if (me->apply_condition("killer") < 1) 
                return notify_fail("������ͨ������\n");
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>2)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
        message_vision(MAG"$N�����˵��ϣ���ʼ������£����ѽ��������ڡ�����\n\n"NOR,me);
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        me->apply_condition("killer",0);
//        me->add("betrayer",-1);
//        me->set("title","��ͨ����");
//        me->set("class","0");
//        me->delete("family");
//        me->delete("party");
        me->start_busy(3);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}

