// story:shenzhao ��Ѫ��צ

#include <ansi.h>

int give_gift();


mixed *story = ({
        "�������Ѷ��С�",
        "���ţ���д��ʲô����",
        "С���������ʦ������д�š��伦�¡������֡�",
        "��ͳ����... ���ã��ҵ������С����������Ĳ����������ٳ��ˣ�",
        "���䣡¡¡����",
        "���Σ��ٺ٣���ͳ���Ķ��ܣ���Ϊ�����Ĵ�����������������߾��ߣ�",
        "��ͳ��κ�ӽ����أ�",
        "С���������ʦ��κ�ӽ�����ǰͷ���Ѿ������ˡ�",
        "��ͳ�����ҽ����أ�",
        "С���������ʦ�����Ͻ����ں�ͷ����û����ȡ�",
        "��ͳ�������̵ģ�����һ������������ǡ�ø����м䣡",
        "���Σ��ż���",
        "��������",
        "��ͳ�������ۣ����ڵ��ϣ������³�������Ѫ�����ˡ�",
        "......",
        "һ���ȥ��...",
        "ʮ���ȥ��...",
        "һ�����ȥ��...",
        "һǧ���ȥ��...",
        "����������ɽ��... �ף�����ʲô��",
        "�ҶѴ���һ�ѿݹǣ��м�����б��飿",
        "���췭�˳����������Ȿ���ƺ�����һ��Ĳ�����д�ġ�",
        "�������ֵǮѽ�������ҿ���....",
        "���ţ�������㣿��",
        "���쿴�˿�˵������ʲô�����⣬ԭ����ֵǮ�����ְѹ����������ˡ�",
        (: give_gift :),
});

void create()
{
        seteuid(getuid());
}



mixed query_story_message(int step)
{
        return step < sizeof(story) ? story[step] : 0;
}

int give_gift()
{
         
        int i;
        object env,ob;
        object *players;
                object gob;
        string msg;

        players = users();
        if (sizeof(players) >= 10)
        {
                for (i = 0; i < 10; i++)
                {
                        ob = players[random(sizeof(players))];
                        if (wizardp(ob)) continue;
                        if (ob->is_fighting()) continue;
                        if (!environment(ob)) continue;
                        if (ob->query_temp("netdead")) continue;
                                
                }
        if(!ob) return 1;
        gob = new(__DIR__"obj/guigu");
        gob->move(ob, 1);
 if (ob)
{
        CHANNEL_D->do_channel(this_object(), "rumor", "��˵" + ob->name(1) +
                              "�������顶������㡷��");
}
        STORY_D->remove_story("new10");
      }
        return 1;
}