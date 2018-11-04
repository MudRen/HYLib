// hongniang.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("����", ({ "hong niang","hong" }) );
        set("title", "����ׯ");
        set("gender", "Ů��" );
        set("age", 16);
        set("long",
                "һλ�����ݵ�С���\n");
        set("max_qi",800);
        set("max_jing",800);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "��Լ" : "�ǰ���������Ϳ��Ե޽�ͽ����Լ",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 200);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object marry_card1,marry_card2, obj, me;
        object *list,ob;
        int i, have_marry;
        me = this_player();
        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        if((string)me->query("gender")=="����"){
              say("����Ц��: ��λ���������ⲻ�ǿ���Цô��\n");
              return 1;
            }
        if ( (string)me->query("class")=="bonze")
           return notify_fail("����Ц���: ���ǳ����ˣ���ʲô�飡����Ϊ���ǲ�����а���\n");
        if ( (int)me->query("age")<17)
             return notify_fail("����Ц��: �����仹С���ȵ�ʮ���������ɡ�\n");
        if ( me->query("couple/couple_id"))
                return notify_fail("�����������: ���Ѿ�����˰ɣ�\n");
//        while (i--) {
//              if (((string)list[i]->query("id")) == "marrycard")
//                return notify_fail("������۴���������ֵ�: ���Ѿ��ͱ����л�Լ�˰ɣ�\n");
//        }

        if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg)|| !find_living(arg))
        return notify_fail("����Ц��: �����˭�޽���Ե��\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "����Ц��: ���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");

        if( !living(obj) )
                return notify_fail("����̾��������˵��: "+obj->name()+
                "�Ѿ��޷�����޽���Ե�ˡ�\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("����Ц��: ͬ������û��˵����\n");

        if(obj==me) return notify_fail("����Ц��: ���Լ��޽��Լ�����в�����\n");

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)))){
                message_vision(MAG "\n$N����$n˵����"+ RANK_D->query_self(me)
                    + me->name() + "��Ը���"+ RANK_D->query_respect(obj)
                    + "��Ϊ��\n\n"NOR, me,obj);
                me->set("marks/"+obj->name(1), 1);
                tell_object(obj, MAG "�����Ը��ͶԷ���Ϊ�򸾣�����Ҳ��"
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "��һ�� marry ָ�\n" NOR);
                write(MAG "�����㼱�����������������˵ͬ�⡭��\n" NOR);
                return 1;
        }

//        marry_card1 = new(__DIR__"obj/marry_card");
//        marry_card1->set("name","���"+obj->query("id")+"�Ļ�Լ");
//        marry_card1->move(me);
//        marry_card2 = new(__DIR__"obj/marry_card");
//        marry_card2->set("name","���"+me->query("id")+"�Ļ�Լ");
//        marry_card2->move(obj);
        me->set("couple/have_couple",1);
        me->set("couple/couple_id", obj->query("id"));
        me->set("couple/couple_name", obj->query("name"));
        obj->set("couple/have_couple",1);
        obj->set("couple/couple_id", me->query("id"));
        obj->set("couple/couple_name", me->query("name"));
        if (me->query("gender")=="����")
        {
                obj->set("couple/couple_gender", "�ɷ�");
                me->set("couple/couple_gender", "����");
        }
        else
        {
                me->set("couple/couple_gender", "�ɷ�");
                obj->set("couple/couple_gender", "����");
        }

        message_vision(MAG"��ϲ $N �� $n ��һ���������ϲ����Ե��\n"NOR,obj,me);
        CHANNEL_D->do_channel(this_object(), "chat",
                sprintf( "%s �� %s ���ڿ�ʼ�Ƿ���! \n",
                me->name(1), obj->name(1)));
        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object *list,ob, couple_ob,nob;
        mapping my_skl;
        string *skl_name;
        int i, have_marry,*level;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;

        me = this_player();
        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        while (i--)
        {
                if (((string)list[i]->query("id")) == "marrycard")
                {
                        marry_card1 = list[i];
                        cardname = list[i]->query("name");
                        have_marry = 1;
                }
        }

if(!arg)   {
             tell_object(me,"��Ҫ��˭��鰡��\n");
             return 1;
            }

//        if (have_marry == 0)
//                return notify_fail("����Ц��: �㻹δ�л�Լ����\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
           return notify_fail("����Ц��: ���Ǳ�Ǹ��������һ�µ�����ׯ�����Ұɡ�\n");
        if (!me->query("couple/couple_id"))
                return notify_fail("����Ц��: ��û�а��¡�\n");
	nob = new(LOGIN_OB);
	nob->set("id", me->query("couple/couple_id"));
	if( !nob->restore() )
{
        me->set("couple/have_couple",0);
        me->set("couple/couple_id", 0);
        me->set("couple/couple_name", 0);
        me->set("couple/couple_gender", 0);
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
                  }

                return notify_fail("���ڰ����Ѿ���������������ˣ���Լֱ�ӽ����\n");
}
//        if (sscanf(cardname,"���%s�Ļ�Լ" ,target)!=1)
//                return notify_fail("����Ц��: ��û�а��¡�\n");
//         if(!objectp(couple_ob = present(target, environment(me)))|| !find_player(target) )
         if(!objectp(couple_ob = present(arg, environment(me))) || !find_player(arg) )
                return notify_fail("����Ц��: ��İ������ڲ��ڳ�.\n");

        if ((string)couple_ob->query("gender") != "Ů��") {
                tmpstr1 = "����"; tmpstr2 = "�Ϲ�";
                str1 = "��"; str2 = "��";
        } else {
                tmpstr1 = "�Ϲ�"; tmpstr2 = "����";
                str1 = "��"; str2 = "��";
        }

        list = all_inventory(couple_ob);
        i = sizeof(list);
//        have_marry = 0;
//        while (i--) {
//              if (((string)list[i]->query("id")) == "marrycard") {
//                        marry_card2 = list[i];
//                        have_marry = 1;
//                }
//        }
//        if (have_marry = 0) {
//                destruct(marry_card1);
//        message_vision(MAG " $N �� $n �����ڿ�ʼ�����Լ!\n" NOR,
//        couple_ob, me);
//        CHANNEL_D->do_channel(this_object(), "chat",
//        sprintf( "��ɢ����Ե��%s �� %s �ӽ��Ժ�����ַɣ��������! \n",
//        me->name(1), couple_ob->name(1)));

//                return 1;
//        }

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) )
        {
                message_vision(MAG "\n$N����$n˵����" + RANK_D->query_self(me)
                        + me->name() + "�����ǽ����Լ��!����?\n\n"
                        NOR, me, couple_ob);
                me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
                tell_object(couple_ob, MAG "�����Ը������Լ������Ҳ"
                        + "��һ�� unmarry ָ�\n" NOR);
                write(MAG "������ֻ�е���" +str2 +" ͬ����...\n" NOR);
                return 1;
        }
//        destruct(marry_card1);
//        destruct(marry_card2);
        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>3)
        		me->set_skill(skl_name[i],level[i]-2);
}
                  }
        me->set("couple/have_couple",0);
        me->set("couple/couple_id", 0);
        me->set("couple/couple_name", 0);
        me->set("couple/couple_gender", 0);
        couple_ob->set("couple/have_couple",0);
        couple_ob->set("couple/couple_id", 0);
        couple_ob->set("couple/couple_name", 0);
        couple_ob->set("couple/couple_gender", 0);
//        my_skl=couple_ob->query_skills();
        message_vision(MAG" $N �� $n �����ڿ�ʼ�����Լ!\n"NOR,couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "��ɢ����Ե��%s �� %s �ӽ��Ժ�����ַɣ��������! \n",
        me->name(1), couple_ob->name(1)));

        return 1;
}
